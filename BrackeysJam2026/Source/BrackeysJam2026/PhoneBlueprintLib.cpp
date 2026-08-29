// Fill out your copyright notice in the Description page of Project Settings.


#include "PhoneBlueprintLib.h"
#include "Kismet/KismetMathLibrary.h"


FString UPhoneBlueprintLib::PrintHint(bool canCall)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "UPhoneBlueprintLib::PrintHint()");

	if (!canCall)
		return FString("You can't call right now");

	return FString("Killer Hint");
}

int UPhoneBlueprintLib::GetTotalLiveBullets(TArray<bool> BulletsChamber)
{
	int liveBulletsCounter = 0;

	for (bool chamber : BulletsChamber)
	{
		if (IsLiveBullet(chamber))
		{
			liveBulletsCounter++;
		}
	}

	return liveBulletsCounter;
}

FString UPhoneBlueprintLib::GetHint(bool canCall, const int& totalLiveBullets)
{
	if (!canCall)
		return FString("You can't call right now");

	FString hintString;

	if (totalLiveBullets > 0)
	{
		int randomHint = UKismetMathLibrary::RandomInteger(totalLiveBullets);
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, FString::FromInt(randomHint));
		switch (randomHint)
		{
			case 0:
				hintString = "Smell Hint";
				break;
			case 1:
				hintString = "Killer Hint";
				break;
			case 2:
				hintString = "Weight Hint";
				break;
		}

		canCall = false;

		return hintString;
	}

	return hintString;
}

bool UPhoneBlueprintLib::IsLiveBullet(bool chamber)
{
	return chamber == true;
}

bool UPhoneBlueprintLib::IsLiveFirstBulletFromArray(TArray<bool> BulletsChamber)
{
	if (BulletsChamber.Num() == 0)
	{
		return false;
	}

	return BulletsChamber[0];
}

bool UPhoneBlueprintLib::IsPhoneCallable(const bool& canCall)
{
	return canCall;
}

bool UPhoneBlueprintLib::CallForHint(bool& canCall)
{
	canCall = true;
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "UPhoneBlueprintLib::CallForHint()");
	FString call = canCall ? "True" : "False";
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, call);

	return canCall;
}

bool UPhoneBlueprintLib::TurnOffOnCall(bool& canCall)
{
	canCall = !canCall;

	return canCall;
}

void UPhoneBlueprintLib::SetActorCollisionToFalse(AActor* actor, const bool& canCall)
{
	if (canCall)
	{
		return;
	}
	actor->SetActorEnableCollision(false);
	
	bool isCollision = actor->GetActorEnableCollision();
	FString collision = isCollision ? "True" : "False";
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, collision);
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Green, "SetActorCollisionToFalse()");
}



