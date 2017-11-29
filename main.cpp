#include <iostream>
#include <fstream>
using namespace std;
#include <CGAL/Simple_cartesian.h>
#include <CGAL/Polygon_2.h>

typedef CGAL::Simple_cartesian<double> Kernel;
typedef Kernel::Point_2 Point_2;
typedef Kernel::Segment_2 Segment_2;
typedef CGAL::Polygon_2<Kernel> Polygon_2;

void read_from_file(string filename);

int main()
{
  string filename;
  cout << "What is the file name?\n";
  cin >> filename;

  read_from_file(filename);

  Point_2 p(1,1), q(10,10), m(5,9);
  cout << "point p = " << p << endl;
  cout << "point q = " << q.x() << " " << q.y() << endl;
  cout << "point m = " << m.x() << " " << m.y() << endl;
  cout << "sqdist(p,q) = " 
            << CGAL::squared_distance(p,q) << endl;
  
  Segment_2 s(p,q);

  cout << "sqdist(Segment_2(p,q), m) = "
            << CGAL::squared_distance(s,m) << endl;

  cout << "p, q, and m ";

  switch (CGAL::orientation(m, q, p)) {
    case CGAL::COLLINEAR:
      cout << "are collinear" << endl;
      break;
    case CGAL::LEFT_TURN:
      cout << "make a left turn" << endl;
      break;
    case CGAL::RIGHT_TURN:
      cout << "make a right turn" << endl;
      break;
  }

  cout << " midpoint(p,q) = " << CGAL::midpoint(p,q) << endl;

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

void read_from_file(string filename){
  ifstream infile;
  infile.open(filename.c_str());
  string next_point;

  while (!infile.eof()){
    infile >> next_point;
    cout << next_point << endl;
  }

  return;
}







