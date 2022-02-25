package sdl2;

import sdl2.events.Event;

/**
 * Allows usage of the SDL Events subsystem.
 */
public class SDLEvents {

    private SDLEvents() {}

    /**
     * Polls for subsystem events, waiting until an event occurs or
     * the wait timeout occurs.
     *
     * @param timeoutMs max wait time in milliseconds.
     * @return polled event, or NULL if timeout is reached or
     *      the generated event is not supported by this binding.
     */
    public static native Event waitEventTimeout(int timeoutMs);
}
