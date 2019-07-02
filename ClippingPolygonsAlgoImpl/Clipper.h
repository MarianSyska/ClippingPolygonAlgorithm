#pragma once
#include <vector>
#include <memory>

typedef struct Vector2{
	float x;
	float y;
	float z;
} Vector2;

typedef struct SweepEvent {
		Vector2 point;
		std::weak_ptr<SweepEvent> other;
		unsigned left : 1;
		unsigned inOut : 1;
		unsigned inside : 1;
		PolygonType pt;

		
} SweepEvent;

enum PolygonType {
	subject = 0, clipper = 0
};

class Clipper {
	public:
		static std::vector<std::vector<Vector2>> *Clipper::getIntersection(std::vector<Vector2> subject, std::vector<Vector2> clipper);
};