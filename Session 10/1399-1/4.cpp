#include <iostream>

using namespace std;

int main() {

	int n, k;
	cin >> n >> k;

	int a[ n ][ n ];
	for ( int i = 0; i < n; i++ )
		for ( int j = 0; j < n; j++ )
			cin >> a[ i ][ j ];

	for ( int m = 1; m <= k; m++ ) {
		int tmp[ n ][ n ];
		for ( int i = 0; i < n; i++ ) {
			for ( int j = 0; j < n; j++ ) {
				int sick = 0, good = 0;
				if ( i + 1 < n )
					if ( a[ i + 1 ][ j ] )
						sick++;
					else
						good++;
				if ( i - 1 >= 0 )
					if ( a[ i - 1 ][ j ] )
						sick++;
					else
						good++;
				if ( j + 1 < n )
					if ( a[ i ][ j + 1 ] )
						sick++;
					else
						good++;
				if ( j - 1 >= 0 )
					if ( a[ i ][ j - 1 ] )
						sick++;
					else
						good++;
				if ( i + 1 < n && j + 1 < n )
					if ( a[ i + 1 ][ j + 1 ] )
						sick++;
					else
						good++;
				if ( i - 1 >= 0 && j - 1 >= 0 )
					if ( a[ i - 1 ][ j - 1 ] )
						sick++;
					else
						good++;
				if ( i + 1 < n && j - 1 >= 0 )
					if ( a[ i + 1 ][ j - 1 ] )
						sick++;
					else
						good++;
				if ( i - 1 >= 0 && j + 1 < n )
					if ( a[ i - 1 ][ j + 1 ] )
						sick++;
					else
						good++;

				if ( sick > good )
					tmp[ i ][ j ] = 1;
				else if ( good > sick )
					tmp[ i ][ j ] = 0;
				else
					tmp[ i ][ j ] = a[ i ][ j ];
			}
		}

		for ( int i = 0; i < n; i++ )
			for ( int j = 0; j < n; j++ )
				a[ i ][ j ] = tmp[ i ][ j ];
	}

	for ( int i = 0; i < n; i++ ) {
		for ( int j = 0; j < n; j++ )
			cout << a[ i ][ j ] << " ";
		cout << endl;
	}

	return 0;
}
