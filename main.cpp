#include <iostream>
using namespace std;
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polygon_2.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;
typedef CGAL::Polygon_2<Kernel> Polygon_2;

int main()
{
  // Point_2 p(1,1), q(10,10);
  // cout << "point p = " << p << endl;
  // cout << "point q = " << q.x() << " " << q.y() << endl;
  // cout << "sqdist(p,q) = " 
  //           << CGAL::squared_distance(p,q) << endl;
  
  // Segment_2 s(p,q);
  // Point_2 m(5, 9);
  
  // cout << "m = " << m << endl;
  // cout << "sqdist(Segment_2(p,q), m) = "
  //           << CGAL::squared_distance(s,m) << endl;
  // cout << "p, q, and m ";
  // switch (CGAL::orientation(p,q,m)){
  // case CGAL::COLLINEAR: 
  //   cout << "are collinear\n";
  //   break;
  // case CGAL::LEFT_TURN:
  //   cout << "make a left turn\n";
  //   break;
  // case CGAL::RIGHT_TURN: 
  //   cout << "make a right turn\n";
  //   break;
  // }
  // cout << " midpoint(p,q) = " << CGAL::midpoint(p,q) << endl;

  Point_2 points[3];

  for (int i = 0; i < 3; i++) {
    Point_2 point(i, i^2);
    cout << point << endl;
    points[i] = point;
  }

  Polygon_2 polygon(points, points + 3);

  if (polygon.is_simple()) {
    cout << "The polygon is simple." << endl;
  } else {
    cout << "The polygon is not simple." << endl;
  }

  return 0;
}