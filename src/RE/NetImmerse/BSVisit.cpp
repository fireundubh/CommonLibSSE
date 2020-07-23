#include "RE/NetImmerse/BSVisit.h"

#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiAVObject.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiObjectNET/NiAVObject/NiNode/NiNode.h"
#include "RE/NetImmerse/NiRefObject/NiObject/NiCollisionObject/NiCollisionObject.h"


namespace RE
{
	namespace BSVisit
	{
		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func)
		{
			if (!a_object) {
				return BSVisitControl::kContinue;
			}

			auto geom = a_object->AsGeometry();
			if (geom) {
				return a_func(geom);
			}

			auto result = BSVisitControl::kContinue;
			auto node = a_object->AsNode();
			if (node) {
				for (auto& child : node->children) {
					result = TraverseScenegraphGeometries(child.get(), a_func);
					if (result == BSVisitControl::kStop) {
						break;
					}
				}
			}

			return result;
		}


		BSVisitControl TraverseScenegraphCollision(NiAVObject* a_object, std::function<BSVisitControl(NiCollisionObject*)> a_func)
		{
			if (!a_object) {
				return BSVisitControl::kContinue;
			}

			auto collision = a_object->collisionObject.get();
			if (collision) {
				return a_func(collision);
			}

			auto result = BSVisitControl::kContinue;
			auto node = a_object->AsNode();
			if (node) {
				for (auto& child : node->children) {
					result = TraverseScenegraphCollision(child.get(), a_func);
					if (result == BSVisitControl::kStop) {
						break;
					}
				}
			}

			return result;
		}
	}
}
