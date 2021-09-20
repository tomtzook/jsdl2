package sdl2.events;

public abstract class Event {

    private final EventType mType;

    public Event(EventType type) {
        mType = type;
    }

    public Event(int type) {
        this(EventType.fromRawValue(type));
    }

    public EventType getType() {
        return mType;
    }
}
