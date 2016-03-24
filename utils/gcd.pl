#!/usr/bin/env perl
#
# ===============================================================
#
# Filename:	gcd.pl
#
# Author:		Oxnz
# Email:		yunxinyi@gmail.com
# Created:		[2015-11-16 13:53:23 CST]
# Last-update:	2015-11-16 13:53:23 CST
# Description: ANCHOR
#
# Version:		0.0.1
# Revision:	[None]
# Revision history:	[None]
# Date Author Remarks:	[None]
#
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

sub gcd {
	my ($m, $n) = @_;
	until ($n == 0) {
		($m, $n) = ($n, $m % $n);
	}
	return $m;
}

use Test::More;

ok(0 == gcd(0, 0));
ok(1 == gcd(1, 0));
ok(1 == gcd(0, 1));
ok(1 == gcd(1, 1));
ok(1 == gcd(2, 1));
ok(2 == gcd(2, 2));
ok(1 == gcd(2, 3));
ok(1 == gcd(3, 2));
ok(2 == gcd(6, 2));
ok(3 == gcd(6, 3));
done_testing();
