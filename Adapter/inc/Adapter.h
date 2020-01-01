//
// Created by Elena on 2020/1/1.
//

#ifndef ADAPTER_ADAPTER_H
#define ADAPTER_ADAPTER_H

#endif //ADAPTER_ADAPTER_H

#ifndef OBJECT_ORIENTED_SUPPORT
#define class typedef struct
#define interface typedef struct
#define abstract
#define public
#define private

#endif


interface RowingBoat{
    void (*row)(void *);
}RowingBoat;


class FishingBoat{
    void (*sail)(void);
}FishingBoat;
FishingBoat *newFishingBoat(void);
void delFishingBoat(FishingBoat *self);

#define implements_RowingBoat
class FishingBoatAdapter implements_RowingBoat{
    RowingBoat super;
    private FishingBoat *boat;
}FishingBoatAdapter;
FishingBoatAdapter *newFishingBoatAdapter(void);
void delFishingBoatAdapter(FishingBoatAdapter *self);

class Captain Captain;
class Captain{
    private RowingBoat *rowingBoat;
    void (*setRowingBoat)(RowingBoat *rowingBoat);
    void (*row)();
}Captain;
Captain *newCaptain(RowingBoat *rowingBoat);
void delCaptain(Captain *self);
