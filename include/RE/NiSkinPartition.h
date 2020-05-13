#pragma once

#include "RE/MemoryManager.h"
#include "RE/NiGeometryData.h"
#include "RE/NiObject.h"


namespace RE
{
	struct ID3D11Buffer;


	class NiSkinPartition : public NiObject
	{
	public:
		inline static constexpr auto RTTI = RTTI_NiSkinPartition;
		inline static constexpr auto Ni_RTTI = NiRTTI_NiSkinPartition;


		enum VertexAttribute : UInt8
		{
			VA_POSITION = 0x0,
			VA_TEXCOORD0 = 0x1,
			VA_TEXCOORD1 = 0x2,
			VA_NORMAL = 0x3,
			VA_BINORMAL = 0x4,
			VA_COLOR = 0x5,
			VA_SKINNING = 0x6,
			VA_LANDDATA = 0x7,
			VA_EYEDATA = 0x8,
			VA_COUNT = 9
		};


		enum VertexFlags : UInt16
		{
			VF_VERTEX = 1 << VA_POSITION,
			VF_UV = 1 << VA_TEXCOORD0,
			VF_UV_2 = 1 << VA_TEXCOORD1,
			VF_NORMAL = 1 << VA_NORMAL,
			VF_TANGENT = 1 << VA_BINORMAL,
			VF_COLORS = 1 << VA_COLOR,
			VF_SKINNED = 1 << VA_SKINNING,
			VF_LANDDATA = 1 << VA_LANDDATA,
			VF_EYEDATA = 1 << VA_EYEDATA,
			VF_FULLPREC = 0x400
		};


		enum VertexMasks : UInt64
		{
			DESC_MASK_VERT = 0xFFFFFFFFFFFFFFF0LL,
			DESC_MASK_UVS = 0xFFFFFFFFFFFFFF0FLL,
			DESC_MASK_NBT = 0xFFFFFFFFFFFFF0FFLL,
			DESC_MASK_SKCOL = 0xFFFFFFFFFFFF0FFFLL,
			DESC_MASK_DATA = 0xFFFFFFFFFFF0FFFFLL,
			DESC_MASK_OFFSET = 0xFFFFFF0000000000LL,
			DESC_MASK_FLAGS = ~(DESC_MASK_OFFSET)
		};


		struct TriShape
		{
			ID3D11Buffer*	vertexBuffer;	// 00
			ID3D11Buffer*	indexBuffer;	// 08
			UInt64			vertexDesc;		// 10
			volatile UInt32 refCount;		// 18
			UInt32			pad1C;			// 1C
			UInt8*			rawVertexData;	// 20
			UInt16*			rawIndexData;	// 28
		};
		STATIC_ASSERT(sizeof(TriShape) == 0x30);


		class Partition
		{
		public:
			UInt64	  vertexDesc;	   // 00
			UInt16*	  bones;		   // 08
			float*	  weights;		   // 10
			UInt16*	  vertexMap;	   // 18
			UInt8*	  bonePalette;	   // 20
			UInt16*	  triList;		   // 28
			UInt16*	  stripLengths;	   // 30
			UInt16	  vertices;		   // 38
			UInt16	  triangles;	   // 3A
			UInt16	  numBones;		   // 3C
			UInt16	  strips;		   // 3E
			UInt16	  bonesPerVertex;  // 40
			UInt16	  pad42;		   // 42
			float	  unk44;		   // 44
			TriShape* buffData;		   // 48
		};
		STATIC_ASSERT(sizeof(Partition) == 0x50);


		virtual ~NiSkinPartition();	 // 00

		// override (NiObject)
		virtual const NiRTTI* GetRTTI() const override;							 // 02
		virtual void		  LoadBinary(NiStream& a_stream) override;			 // 18
		virtual void		  LinkObject(NiStream& a_stream) override;			 // 19 - { NiObject::LinkObject(a_stream); }
		virtual bool		  RegisterStreamables(NiStream& a_stream) override;	 // 1A - { return NiObject::RegisterStreamables(a_stream); }
		virtual void		  SaveBinary(NiStream& a_stream) override;			 // 1B
		virtual bool		  IsEqual(NiObject* a_object) override;				 // 1C

		// add
		virtual void Unk_25(void);	// 25

		static VertexFlags GetVertexFlags(UInt64 vertexDesc)
		{
			return VertexFlags((vertexDesc & DESC_MASK_OFFSET) >> 44);
		}


		// members
		UInt32				   numPartitions;  // 10
		UInt32				   pad14;		   // 14
		SimpleArray<Partition> partitions;	   // 18
		UInt64				   unk20;		   // 20
	};
	STATIC_ASSERT(sizeof(NiSkinPartition) == 0x28);
}
