#!/usr/bin/env perl

use warnings;
use strict;
use integer;

sub dec2bin {
	$_ = $_[0];
	if ($_ > 1) {
		my $x = $_ % 2;
		return dec2bin($_/2).$x;
	} else {
		return $_;
	}
}

sub factorial {
	my ($n) = @_;
	return 1 if $n == 0;
	return factorial($n-1) * $n;
}

sub hanoi {
	my ($n, $start, $end, $mid) = @_;
	if ($n == 1) {
		print "$start --->#1---> $end\n"; # step 1
	} else {
		hanoi($n-1, $start, $mid, $end); # step 2
		print "$start --->#$n---> $end\n"; # step 3
		hanoi($n-1, $mid, $end, $start); # step 4
	}
}

#hanoi($ARGV[0], 'A', 'C', 'B');

sub dirwalk {
	my ($top, $filefunc, $dirfunc) = @_;
	my $DIR;

	if (-d $top) {
		unless (opendir $DIR, $top) {
			warn "Couldn't open directory $top: $!; skipping.\n";
			return;
		}
		my @files;
		foreach (readdir $DIR) {
			next if $_ eq '.' || $_ eq '..';
			push @files, dirwalk("$top/$_", $filefunc, $dirfunc);
		}
		closedir $DIR or warn "closedir failed: $!\n";
		return $dirfunc ? $dirfunc->($top, @files) : ();
	} else {
		return $filefunc ? $filefunc->($top) : ();
	}
}


print dirwalk('.', sub {$_[0]}, sub{shift;return @_});
