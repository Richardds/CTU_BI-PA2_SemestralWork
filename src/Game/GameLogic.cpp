#include "GameLogic.h"

SW::GameLogic::GameLogic() : _tick(TICK_DEFUALT), _tick_last(0) {
    this->_tick_last = SDL_GetTicks();
}

void SW::GameLogic::process(const Renderer & renderer, const Window & window) {
    if (this->tick()) {
        _Info("WORLD TICK");
    }

    // Rectangle test
    Rectangle rect;
    rect.moveToWindowCenter(window);
    rect.setColor(Color(255, 0, 0));
    rect.render(renderer);

}

bool SW::GameLogic::tick() {
    uint32_t tick_current = SDL_GetTicks();
    if (tick_current - this->_tick_last >= this->_tick) {
        this->_tick_last = tick_current;
        return true;
    }
    return false;
}
