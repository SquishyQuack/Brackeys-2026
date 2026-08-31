// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RevolverBlueprintLib.generated.h"

/**
 * 
 */
UCLASS()
class BRACKEYSJAM2026_API URevolverBlueprintLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "URevolverBlueprintLib")
	static void LoadBullets(TArray<bool>& BulletsChamber, int32& maxLiveBullets, int32& bulletsRemaining);
	
};
