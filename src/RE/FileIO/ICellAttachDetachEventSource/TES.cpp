#include "RE/FileIO/ICellAttachDetachEventSource/TES.h"

#include "RE/FormComponents/Components/GridArray/GridCellArray.h"
#include "RE/FormComponents/TESForm/TESObjectCELL.h"


namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Relocation<TES**> singleton{ Offset::TES::Singleton };
		return *singleton;
	}


	void TES::ForEachReference(std::function<bool(TESObjectREFR& a_ref)> a_callback)
	{
		auto cell = interiorCell;
		if (cell) {
			cell->ForEachReference([&](RE::TESObjectREFR& a_ref) {
				return a_callback(a_ref);
			});
		} else {
			if (gridCells) {
				const auto gridLength = gridCells->length;
				if (gridLength > 0) {
					for (std::uint32_t x = 0, y = 0; x < gridLength && y < gridLength; x++, y++) {
						cell = gridCells->GetCell(x, y);
						if (cell && cell->IsAttached()) {
							cell->ForEachReference([&](RE::TESObjectREFR& a_ref) {
								return a_callback(a_ref);
							});
						}
					}
				}
			}
		}
	}


	void TES::ForEachReferenceInRange(const NiPoint3& a_origin, float a_radius, std::function<bool(TESObjectREFR& a_ref)> a_callback)
	{
		auto cell = interiorCell;
		if (cell) {
			cell->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
				return a_callback(a_ref);
			});
		} else {
			if (gridCells) {
				const auto gridLength = gridCells->length;
				if (gridLength > 0) {
					const float yPlus = a_origin.y + a_radius;
					const float yMinus = a_origin.y - a_radius;
					const float xPlus = a_origin.x + a_radius;
					const float xMinus = a_origin.x - a_radius;

					for (std::uint32_t x = 0, y = 0; x < gridLength && y < gridLength; x++, y++) {
						cell = gridCells->GetCell(x, y);
						if (cell && cell->IsAttached()) {
							const auto cellCoords = cell->GetCoordinates();
							if (cellCoords && (cellCoords->worldX < xPlus && (cellCoords->worldX + 4096.0f) > xMinus && cellCoords->worldY < yPlus && (cellCoords->worldY + 4096.0f) > yMinus)) {
								cell->ForEachReferenceInRange(a_origin, a_radius, [&](RE::TESObjectREFR& a_ref) {
									return a_callback(a_ref);
								});
							}
						}
					}
				}
			}
		}
	}
	
	
	float TES::GetWaterHeight(const RE::NiPoint3& a_pos, TESObjectCELL* a_cell)
	{
		using func_t = decltype(&TES::GetWaterHeight);
		REL::Relocation<func_t> func{ REL::ID(13212) };
		return func(this, a_pos, a_cell);
	}
}
