// Fill out your copyright notice in the Description page of Project Settings.


#include "RevolverBlueprintLib.h"
#include <Kismet/KismetMathLibrary.h>
#include "Math/UnrealMathUtility.h"

void URevolverBlueprintLib::LoadBullets(TArray<bool>& BulletsChamber, int32& maxLiveBullets, int32& bulletsRemaining)
{
	const int32 min = 1;
	const int32 max = 3;
	int32 random = UKismetMathLibrary::RandomInteger(max);
	maxLiveBullets = UKismetMathLibrary::Clamp(random, min, max);


	for (int i = 0; i < maxLiveBullets ; ++i)
	{
		BulletsChamber.Add(true);
	}

	while (BulletsChamber.Num() < 6)
	{
		BulletsChamber.Add(false);
	}

	for (int32 i = BulletsChamber.Num() - 1; i > 0; --i)
	{
		const int32 j = FMath::RandRange(0, 1);
		BulletsChamber.Swap(i, j);
	}

	bulletsRemaining = BulletsChamber.Num();
}
