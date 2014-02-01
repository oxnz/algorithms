#!/usr/bin/env perl

use Benchmark;

sub logbase1 { # Compute the value each time.
	my ($base, $numbers) = @_;
	my @result;
	for (my $i = 0; $i < @$numbers; $i++) {
		push @result, log($numbers->[$i]) / log ($base);
	}
	return @result;
}

sub logbase2 { # Store log $base in a temporary variable.
	my ($base, $numbers) = @_;
	my @result;
	my $logbase = log $base;
	for (my $i = 0; $i < @$numbers; $i++) {
		push @result, log($numbers->[$i]) / $logbase;
	}
	return @result;
}

@numbers = (1..1000);

timethese (100000, { no_temp => 'logbase1( 10, \@numbers )',
		temp => 'logbase2( 10, \@numbers )' });
