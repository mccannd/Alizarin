// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "Damageable.h"

// for compilation
UDamageable::UDamageable(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

// for compilation, will replace with more useful function to calculate
void IDamageable::TakeDamage(FDamageStruct damage)
{
	return;
}



