#pragma once

#include "Types.h"
#include <cassert>
#include <vector>


class EntityManager
{
public:
	struct EntityDesc
	{
		EntityID      EnyityID;
		ComponentMask Mask;
	};
public:
	EntityManager()=default;
	EntityID CreateEntity();
	void DestroyEntity(EntityID entity);

	friend class ComponentManager;

private:
	std::vector<EntityIndex> mRecycledEntityIndex{};	//再使用可能のEntity Index及びVersion情報を保存
	std::vector<EntityDesc> mEntityDesc;
};
