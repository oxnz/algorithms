#!/usr/bin/env perl -w
#
# ===============================================================
#
# Filename:	set.pl
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2014-11-23 04:34:43 CST]
# Last-update:	2014-11-23 04:34:43 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
# ref: http://programmingpraxis.com/2012/03/09/sparse-sets/
# License:
# Copyright (c) 2013 Oxnz
#
# Distributed under terms of the [LICENSE] license.
# [license]
#
# ===============================================================
#

use strict;
use warnings;

package SparseSet;

use constant { TRUE => 1, FALSE => 0 };

sub new {
	my $class = shift;
	my $self = bless {
		n => 0,
		dense => [],
		sparse => [],
	}, $class;
	return $self;
}

sub clear {
	my $self = shift;
	$self->{n} = 0;
}

sub contain {
	my $self = shift;
	my $val = shift;
	return undef if $self->{n} <= 0;
	my $idx = $self->{sparse}->[$val];
	return undef if not defined($idx) or $idx >= $self->{n};
	defined($idx) or return undef;
	return $val == $self->{dense}->[$idx];
	return 1;
}

sub insert {
	my $self = shift;
	my $val = shift;
	return undef if $self->contain($val);
	$self->{dense}->[$self->{n}] = $val;
	$self->{sparse}->[$val] = $self->{n};
	++$self->{n}
}

sub remove {
	my $self = shift;
	my $val = shift;
	return undef if not $self->contain($val);
	--$self->{n};
	my $topval = $self->{dense}->[$self->{n}];
	return 1 if $val == $topval;
	my $idx = $self->{sparse}->[$val];
	$self->{sparse}->[$topval] = $idx;
	$self->{dense}->[$idx] = $topval;
	return 1;
}

sub inspect {
	my $self = shift;
	print "sparse set: $self->{n}\n";
	if ($self->{n}) {
		print "elems:\n\t";
		for (my $i = 0; $i < $self->{n}; ++$i) {
			print "[$self->{dense}->[$i]]";
		}
		print "\ndense array:\n\t";
		foreach (@{$self->{dense}}) {
			if (defined($_)) {
				print "[$_]";
			} else {
				print "[ ]";
			}
		}
		print "\nsparse array:\n\t";
		foreach (@{$self->{sparse}}) {
			if (defined($_)) {
				print "[$_]";
			} else {
				print "[ ]";
			}
		}
		print "\n";
	}
}

sub DESTROY {
	#print "destroy";
}

package main;

print "test sparse set:\n";
my $set = SparseSet->new(10);
print "new set:\n";
$set->inspect();
foreach (9, 8, 5, 6, 3) {
	$set->insert($_);
}
print "after insert 9 8 5 6 3\n";
$set->inspect();
$set->remove(5);
print "after remove(5):\n";
$set->inspect();
print "after insert 5 7 1 9 0:\n";
foreach (5, 7, 1, 9, 0) {
	$set->insert($_);
}
$set->inspect();
