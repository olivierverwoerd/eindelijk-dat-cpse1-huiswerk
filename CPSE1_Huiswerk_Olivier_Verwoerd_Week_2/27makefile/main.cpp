// Olivier Verwoerd
#include "hwlib.hpp"
#include "player.hpp"
#include "converter.hpp"

/* @brief main
 * Sets pinout and start playing audio file.
 */
int main(int argc, char **argv)
{
    WDT->WDT_MR = WDT_MR_WDDIS;
    namespace target = hwlib::target;
    hwlib::wait_ms(500);
    auto lsp = target::pin_out(target::pins::d51);
    auto p = lsp_player(lsp);
    play(p, convertme());
    while (true)
    {
    }
}
