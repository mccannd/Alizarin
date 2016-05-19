// Fill out your copyright notice in the Description page of Project Settings.

#include "SpaceDiablo.h"
#include "HitscanWeapon.h"


void AHitscanWeapon::FireHold(FVector origin, FVector direction)
{
	if (!CanFireNextShot()) return;
	
	// if the weapon is single target, do a single trace
	// inflict damage if collided with damageable actor
	

	// otherwise do a multiline trace
	// inflict damage to all damageable actors
	
	// set the next shot timer
	nextShotTime = GetWorld()->TimeSeconds + shotDelay;
}


