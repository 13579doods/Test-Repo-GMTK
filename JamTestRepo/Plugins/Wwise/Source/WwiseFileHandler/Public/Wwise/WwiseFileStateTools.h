/*******************************************************************************
The content of this file includes portions of the proprietary AUDIOKINETIC Wwise
Technology released in source code form as part of the game integration package.
The content of this file may not be used without valid licenses to the
AUDIOKINETIC Wwise Technology.
Note that the use of the game engine is subject to the Unreal(R) Engine End User
License Agreement at https://www.unrealengine.com/en-US/eula/unreal
 
License Usage
 
Licensees holding valid licenses to the AUDIOKINETIC Wwise Technology may use
this file in accordance with the end user license agreement provided with the
software or, alternatively, in accordance with the terms contained
in a written agreement between you and Audiokinetic Inc.
Copyright (c) 2023 Audiokinetic Inc.
*******************************************************************************/

#pragma once

#include "AkInclude.h"

class FString;
class IMappedFileRegion;
class IMappedFileHandle;

class WWISEFILEHANDLER_API FWwiseFileStateTools
{
public:
	virtual ~FWwiseFileStateTools() {}

protected:
	static uint8* AllocateMemory(int64 InMemorySize, bool bInDeviceMemory, int32 InMemoryAlignment, bool bInEnforceMemoryRequirements);
	static void DeallocateMemory(const uint8* InMemoryPtr, int64 InMemorySize, bool bInDeviceMemory, int32 InMemoryAlignment, bool bInEnforceMemoryRequirements);

	static bool GetMemoryMapped(IMappedFileHandle*& OutMappedHandle, IMappedFileRegion*& OutMappedRegion, int64& OutSize,
		const FString& InFilePathname, int32 InMemoryAlignment);
	static bool GetMemoryMapped(IMappedFileHandle*& OutMappedHandle, int64& OutSize,
		const FString& InFilePathname, int32 InMemoryAlignment);
	static bool GetMemoryMappedRegion(IMappedFileRegion*& OutMappedRegion, IMappedFileHandle& InMappedHandle);
	static void UnmapRegion(IMappedFileRegion& InMappedRegion);
	static void UnmapHandle(IMappedFileHandle& InMappedHandle);

	static bool GetFileToPtr(const uint8*& OutPtr, int64& OutSize,
		const FString& InFilePathname, bool bInDeviceMemory, int32 InMemoryAlignment, bool bInEnforceMemoryRequirements,
		int64 ReadFirstBytes = -1);
};
