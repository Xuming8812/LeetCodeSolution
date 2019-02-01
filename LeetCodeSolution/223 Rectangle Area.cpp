#include<vector>
#include<map>
#include<string>
#include<queue>
#include<sstream>
#include<stack>
#include<set>
#include<bitset>
using namespace std;

/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.
*/

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
	if (A<G && C>E && B<H && D>F) {
		return -(min(C, G) - max(E, A))*(min(D, H) - max(F, B)) + (C - A)*(D - B) + (G - E)*(H - F);
	}
	else {
		return (C - A)*(D - B) + (G - E)*(H - F);
	}
}