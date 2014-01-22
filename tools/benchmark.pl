#!/usr/bin/env perl
# a benchmark demo for x^2 + x - 1 = 0 (Golden Ratio)

use strict;
use warnings;
use Benchmark;

sub quadratic { # Compute the larger root of a quadratic polynomial
	my ($a, $b, $c) = @_;
	return (-$b + sqrt($b*$b - 4*$a * $c)) / 2*$a;
}

sub bruteforce { # Search linearly until we find a good-enough choice
	my ($low, $high) = @_;
	for (my $x = $low; $x <= $high; $x += .001) {
		return $x if abs($x * ($x + 1) - .999) < .001;
	}
}

timethese(1000000, { quadratic => 'quadratic(1, 1, -1)',
		bruteforce => 'bruteforce(0, 1)' })
