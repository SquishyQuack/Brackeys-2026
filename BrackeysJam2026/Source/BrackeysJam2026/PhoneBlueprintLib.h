// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhoneBlueprintLib.generated.h"

/**
 * 
 */
UCLASS()
class BRACKEYSJAM2026_API UPhoneBlueprintLib : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category="UPhoneBlueprintLib")
	static FString PrintHint(bool canCall);

	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static int GetTotalLiveBullets(TArray<bool> BulletsChamber);

	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static FString GetHint3(bool canCall, const int& totalLiveBullets);

	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static bool IsLiveBullet(bool chamber);
	
	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static bool IsLiveBulletFromArray(TArray<bool> BulletsChamber);
	
	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static bool IsPhoneCallable(const bool &canCall);

	UFUNCTION(BlueprintCallable, Category = "UPhoneBlueprintLib")
	static bool CallForHint(bool& canCall);

};
