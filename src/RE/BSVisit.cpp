#include "RE/BSVisit.h"

#include "RE/NiAVObject.h"
#include "RE/NiNode.h"


namespace RE
{
	namespace BSVisit
	{
		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, llvm::function_ref<BSVisitControl(BSGeometry*)> a_func)
		{
			if (!a_object) {
				return BSVisitControl::kStop;
			}

			auto geom = a_object->AsGeometry();
			if (geom) {
				return a_func(geom);
			}

			auto result = BSVisitControl::kStop;
			auto node = a_object->AsNode();
			if (node) {
				for (auto& child : node->children) {
					result = TraverseScenegraphGeometries(child.get(), a_func);
					if (result != BSVisitControl::kContinue) {
						break;
					}
				}
			}

			return result;
		}
	}
}
