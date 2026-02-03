#ifndef WORLD_MAP_H
#define WORLD_MAP_H

#define W 30
#define H 30

extern int world_map[W][H];  

void init_world_map(void);
void draw_world_map(void);
void update_map(void);

#endif
