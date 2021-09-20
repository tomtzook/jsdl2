package sdl2;

import sdl2.events.Event;

public class EventsJni {

    private EventsJni() {}

    public static native Event waitEventTimeout(int timeoutMs);
}
