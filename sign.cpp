#include "sign.h"

char symbol(Sign s) {
    switch (s) {
    case Sign::Empty:
        return '.';
    case Sign::X:
        return 'X';
    case Sign::O:
        return 'O';
    }
    return '?';
}
