#!/usr/bin/env perl

use strict;
use warnings;
use Data::Dump;

sub topDownMergeSort {
	topDownSplitMerge(@_, 0, n);
}

sub topDownSplitMerge {
	my ($src, $dst, $istart, $iend) = @_;
	if ($iend - $istart < 2) {
		return;
	}
	my $imid = ($istart + $iend) / 2;
	topDownSplitMerge($src, $dst, $istart, $imid);
	topDownSplitMerge($src, $dst, $imid, $iend);
	topDownMerge($src, $dst, $istart, $imid, $iend);
	copyArray($dst, $src, $istart, $iend);
}

sub topDownMerge {
}
