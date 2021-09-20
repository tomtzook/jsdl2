package sdl2;

public enum GameControllerAxis {
    LEFT_X(0),
    LEFT_Y(1),
    RIGHT_X(2),
    RIGHT_Y(3),
    TRIGGER_LEFT(4),
    TRIGGER_RIGHT(5)
    ;

    private final int mIndex;

    GameControllerAxis(int index) {
        mIndex = index;
    }

    public int index() {
        return mIndex;
    }
}
