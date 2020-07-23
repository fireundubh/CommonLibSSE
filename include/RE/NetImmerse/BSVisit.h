#pragma once


namespace RE
{
	class BSGeometry;
	class NiAVObject;
	class NiCollisionObject;


	namespace BSVisit
	{
		enum class BSVisitControl
		{
			kContinue = 0,
			kStop = 1
		};


		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func);
		BSVisitControl TraverseScenegraphCollision(NiAVObject* a_object, std::function<BSVisitControl(NiCollisionObject*)> a_func);
	}
}
