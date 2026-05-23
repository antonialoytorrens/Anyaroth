#pragma once
// Compatibility shim for projects originally written against Box2D <= 2.3,
// built here against Box2D 2.4 where Set/GetUserData were replaced by a
// b2BodyUserData / b2FixtureUserData struct exposing a uintptr_t pointer.

#include <box2d/box2d.h>
#include <cstdint>

inline void B2SetUserData(b2Body* body, void* data)
{
    body->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

inline void B2SetUserData(b2Fixture* fixture, void* data)
{
    fixture->GetUserData().pointer = reinterpret_cast<uintptr_t>(data);
}

inline void* B2GetUserData(b2Body* body)
{
    return reinterpret_cast<void*>(body->GetUserData().pointer);
}

inline void* B2GetUserData(b2Fixture* fixture)
{
    return reinterpret_cast<void*>(fixture->GetUserData().pointer);
}
