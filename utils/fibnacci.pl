#!/usr/bin/env perl

use warnings;
use strict;

# compute the number of pairs of rabbits alive in month n
{ my %cache;
	sub fib {
		my ($month) = @_;
		unless (exists $cache{$month}) {
			if ($month < 2) { $cache{$month} = 1}
			else {
				$cache{$month} = fib($month-1) + fib($month-2);
			}
		}
		return $cache{$month};
	}
}

foreach (1..$ARGV[0]) {
	print fib($_), "\n";
}

# version 2
use Memoize;
memoize 'fibnacci';

sub fibnacci {
	my ($month) = @_;
	if ($month) < 2) { 1 }
	else {
		fibnacci($month-1) + fibnacci($month-2);
	}
}
