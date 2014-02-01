#!/usr/bin/env perl
use warnings;
use strict;
use memoize qw/memoize/;

sub fib {
	my ($month) = @_;
	if ($month < 2) {1}
	else {
		fib($month-1) + fib($month-2);
	}
}

#*fib = memoize(\&fib);

print fib $ARGV[0];
