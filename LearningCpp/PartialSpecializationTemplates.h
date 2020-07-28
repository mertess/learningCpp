﻿#pragma once

template <typename T, typename G>
struct SameType
{
	static const bool value = false;
};

template <typename T>
struct SameType<T, T>
{
	static const bool value = true;
};

template <typename T>
struct SameType<T, T&>
{
	static const bool value = false;
};

template <typename T>
struct SameType<T, const T>
{
	static const bool value = false;
};

//шаблон от шаблона aka ограничения обобщений
template <class T>
class SomeCollection{};

template<template<class T> class Collection>
Collection<string> toString(Collection<int> coll) { return Collecion<string>; }
