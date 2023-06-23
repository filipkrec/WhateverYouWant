#include "AbilityPlayerState.h"

AAbilityPlayerState::AAbilityPlayerState()
{
}

UAbilitySystemComponent* AAbilityPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UCharacterAttributeSetBase* AAbilityPlayerState::GetAttributeSetBase() const
{
	return AttributeSetBase;
}

float AAbilityPlayerState::GetHealth() const
{
	return AttributeSetBase->GetHealth();
}

void AAbilityPlayerState::BeginPlay()
{
	Super::BeginPlay();
}