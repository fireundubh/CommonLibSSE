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


		BSVisitControl TraverseScenegraphCollision(NiAVObject* a_object, std::function<BSVisitControl(NiCollisionObject*)> a_func);
		BSVisitControl TraverseScenegraphGeometries(NiAVObject* a_object, std::function<BSVisitControl(BSGeometry*)> a_func);		
		BSVisitControl TraverseScenegraphObjects(NiAVObject* a_object, std::function<BSVisitControl(NiAVObject*)> a_func);
	}
}
