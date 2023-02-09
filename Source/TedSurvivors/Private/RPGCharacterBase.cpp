// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacterBase.h"

// Sets default values
ARPGCharacterBase::ARPGCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("TedAbilitySystemComponent"));
}

// Called when the game starts or when spawned
void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (AbilitySystemComponent != nullptr)
	{
		if (PreloadAbilities.Num()>0)
		{
			for (auto i = 0; i<PreloadAbilities.Num(); i++)
			{
				if (PreloadAbilities[i] != nullptr)
				{
					AbilitySystemComponent -> GiveAbility(FGameplayAbilitySpec(PreloadAbilities[i].GetDefaultObject(), 1, 0));
				}
			}
		}
		AbilitySystemComponent -> InitAbilityActorInfo(this, this);
	}
}

// Called every frame
void ARPGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* ARPGCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

