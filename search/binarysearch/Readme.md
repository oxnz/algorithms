BINARY-SEARCH(A, w)

	1. low <- 0
	2. high <- length[A]
	3. while low < high
	4. do try <- int((low + high) / 2)
	5. 		if A[try] > w
	6.		then high <- try
	7.		else if A[try] < w
	8.		then low <- try+1
	9.		else
	10.			return try
	11.		end if
	12. end do
	13. return NO_ELEMENT
