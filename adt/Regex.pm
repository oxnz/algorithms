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

package Regex;

use base qw/Exporter/;
use Stream ':all';
@Regex::EXPORT_OK = qw/literal union concat star plus charclass show matches/;

sub literal {
	my $str = shift;
	node($str, undef);
}

use Data::Dumper;

sub union {
	my ($h, @s) = grep $_, @_;
	print "------------\n";
	print Dumper(@_);
	print "============\n";
	return unless $h;
	return $h unless @s;
	node(head($h), promise { union(@s, tail($h)); });
}

sub precat {
	my ($s, $c) = @_;
	transform { "$c$_[0]" } $s;
}

sub postcat {
	my ($s, $c) = @_;
	transform { "$_[0]$c" } $s;
}

sub concat {
	my ($S, $T) = @_;
	return unless $S && $T;
	my ($s, $t) = (head($S), head($T));
	node("$s$t", promise {
			union(postcat(tail($S), $t),
				precat(tail($T), $s),
				concat(tail($S), tail($T)),
			)
		});
}
