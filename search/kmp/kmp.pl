#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dump;

sub kmpTable {
	my ($pattern, $substring, $pos, $cnd, @table) = (@_, 2, 0, qw(-1 0));

	while ($pos < @$pattern) {
		if ($pattern->[$pos - 1] eq $pattern->[$cnd]) {
			++$cnd;
			$table[$pos] = $cnd;
			++$pos;
		} elsif ($cnd > 0) {
			$cnd = $table[$cnd];
		} else {
			$table[$pos] = 0;
			++$pos;
		}
	}
	return \@table;
}

sub kmpSearch {
	my ($pattern, $substring) = @_;
	my @pattern = split("", $pattern);
	my @substring = split("", $substring);
	my ($m, $i, $table) = (0, 0, kmpTable(\@pattern, \@substring));
	print "pattern = $pattern, substring = $substring, table = \n";
	dd $table;

	while ($m + $i < length($pattern)) {
		if ($substring[$i] eq $pattern[$m+$i]) {
			return $m if ($i == length($substring) - 1);
			++$i;
		} else {
			$m += $i - $table->[$i];
			if ($table->[$i] > -1) {
				$i = $table->[$i];
			} else {
				$i = 0;
			}
		}
	}
	return length($pattern);
}

print "kmp search result: ", kmpSearch(@ARGV), "\n";
