#ifndef HELPER
#define HELPER

bool isInBounds(short file, short rank)
{
    return file >= 0 && file < 8 && rank >= 0 && rank < 8;
}

#endif //HELPER