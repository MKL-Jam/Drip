screen testhouse() {
	screen me;
	unsigned char layer1[SW][SH]={
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,1,1,1,1,0,11,11,11},
		{11,11,2,8,8,8,0,11,11,11},
		{11,11,2,8,8,8,0,11,11,11},
		{11,11,2,8,8,8,16,11,11,11},
		{11,11,2,8,8,8,0,11,11,11},
		{11,11,2,8,8,8,0,11,11,11},
		{11,11,1,1,1,1,0,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11},
		{11,11,11,11,11,11,11,11,11,11}
	};
	char collisions[SW][SH]={
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,1,1,1,1,1,-1,-1,-1},
		{-1,-1,1,1,-1,-1,1,-1,-1,-1},
		{-1,-1,1,-1,-1,-1,1,-1,-1,-1},
		{-1,-1,1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,1,1,-1,-1,1,-1,-1,-1},
		{-1,-1,1,1,1,-1,1,-1,-1,-1},
		{-1,-1,1,1,1,1,1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	};
	char entities[SW][SH]={
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,54,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,55,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,45,53,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
	};
	mapLoader(&entities, &collisions);
	nentitySpawn(ent_aitest());
	nentSet[nspawnSlot-1].x=7*TS;
	nentSet[nspawnSlot-1].y=4*TS;

	me.collisionLayer=collisions;
	me.tileLayer=layer1;
	return me;
}