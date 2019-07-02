#include "Clipper.h"
#include <set>
#include <queue>
#include <memory>

std::vector<std::vector<Vector2>> *Clipper::getIntersection(std::vector<Vector2> subject, std::vector<Vector2> clipper) {
	std::priority_queue<std::shared_ptr<SweepEvent>> events;

	for (int i = 0; i < subject->size; i++) {
		int j = i + subject->size - 1 % subject->size;

		std::shared_ptr<SweepEvent> e1 = std::make_shared();
		std::shared_ptr<SweepEvent> e2 = std::make_shared();

		e1->point = subject.at(i);
		e2->point = subject.at(j);

		e2->left = !(e1->left = subject.at(i).x == subject.at(j).x ? subject.at(i).y < subject.at(j).y : subject.at(i).y < subject.at(j).y);
		

		e1->pt = (PolygonType)0;
		e2->pt = (PolygonType)1;


		e1->other = e2;
	}

	std::set<shared_ptr<SweepEvent>> s;

	for (!events.empty()) {

		event = events.top();
		events.pop();

		
		if (event->left) {

			auto curr = s.insert(event);

			//Set Inside Other Polygon Flag
			std:shared_ptr<SweepEvent> ple = curr.prev().get();
			std:shared_ptr<SweepEvent> le = curr.get();

			if (ple == NULL){
				le.get()->inside = le.get()->inOut = false;
			}
			else if (le->pl == ple->pl) {
				le->inside = ple.get()->inside;
				le->inOut = !ple->inOut;
			}
			else {
				le->inside = !ple->inOut;
				le->inOut = ple->inside;
			}

			// Todo: Calc possible intersection with prev and next of curr in s set
		}
		else {
			auto right = s.find(event->other.lock());

			std:shared_ptr<SweepEvent> next;
			std:shared_ptr<SweepEvent> prev;

			if (right->inside) {
				//Todo: Add to data structure or ignore depending on operation.
			}
			else {
				//Todo: Add to data structure or ignore depending on operation.
			}

			s.erase(right);

			// Todo: Calc possible intersection with prev and next in s set
		}

		


	}

	
	//Todo: Construct Polygon.
	

	//Todo: Return result.
	return nullptr;
}