#pragma once

#ifndef TEZZSNAKE_RANGE_H
#define TEZZSNAKE_RANGE_H

struct Range {
	int start, end;
	
	Range() {
		start = 0;
		end = 0;
	}

	Range( int _start, int _end ) {
		start = _start;
		end = _end;
	}
};

#endif // TEZZSNAKE_RANGE_H