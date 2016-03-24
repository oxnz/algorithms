#!/usr/bin/env perl
#
# Stream.pm - Stream
#
# Copyright (c) 2015, Oxnz
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
# DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
# FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
# DAMAGES(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
# SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
# OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

use strict;
use warnings;

package Stream;

use base qw(Exporter);

@Stream::EXPORT_OK = qw/node head tail
drop upto upfrom show promise
filter transform merge list_to_stream cutsort iterater_function cut_loops/;

%Stream::EXPORT_TAGS = ('all' => \@Stream::EXPORT_OK);

sub node {
	my ($h, $t) = @_;
	[$h, $t];
}

sub head {
	my ($s) = @_;
	$s->[0];
}

sub tail {
	my ($s) = @_;
	if (is_promise($s->[1])) {
		return $s->[1]->();
	}
	$s->[1];
}

sub is_promise {
	UNIVERSAL::isa($_[0], 'CODE');
}

sub promise (&) { $_[0] }

sub upto {
	my ($m, $n) = @_;
	return if $m >= $n;
	node($m, promise { upto($m+1, $n) });
}

sub upfrom {
	my ($m) = @_;
	node($m, promise { upfrom($m+1) });
}

sub drop {
	my $h = head($_[0]);
	$_[0] = tail($_[0]);
	return $h;
}

sub show {
	my ($s, $n) = @_;
	while ($s && (! defined $n || --$n >= 0)) {
		print drop($s), $";
	}
	print $/;
}

sub transform (&$) {
	my $f = shift;
	my $s = shift;
	return unless $s;
	node($f->(head($s)), promise { transform($f, tail($s)) });
}

sub filter (&$) {
	my $f = shift;
	my $s = shift;
	return unless $s;
	node($f->(head($s)), promise { filter($f, tail($s)) });
}

