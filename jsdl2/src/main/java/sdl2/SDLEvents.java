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

    /**
     * Retrieves the next pending event in the event queue.
     *
     * @return pending event, or NULL if no event is pending.
     */
    public static native Event pollEvent();
}
