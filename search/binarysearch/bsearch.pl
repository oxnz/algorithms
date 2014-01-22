#!/usr/bin/env perl
#
# bsearch - search for a word in a list of alphabetically ordered words
# usage: bsearch word filename

use strict;
use warnings;

sub binary_search {
	my ($array, $word) = @_;
	my ($low, $high) = (0, @$array - 1);

	while ( $low <= $high ) {	# While the window is open
		my $mid = int( ($low+$high) / 2 );	# Try the middle element
		$low = $mid + 1, next if $array->[$mid] lt $word; # Raise bottom
		$high = $mid - 1, next if $array->[$mid] gt $word; # Lower top
		return $mid;	# We've found the word
	}
	return;	# The word isn't there.
}

my $word = shift; # Assign first argument to $word
chomp( my @array = <>); # Read in newline-delimited words

($word, @array) = map lc, ($word, @array); # Convert all to lowercase
my $index = binary_search(\@array, $word); # Invoke our algorithm

if (defined $index) { print "$word occurs at position $index.\n" }
else { print "$word doesn't occur.\n" }

# Test
# binary_search.pl binary /usr/share/dict/words
