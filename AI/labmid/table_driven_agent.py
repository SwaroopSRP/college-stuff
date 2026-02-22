def vacuum_reflex_agent(state):
    """
    Multi-step Simple Reflex Agent (2-room vacuum)

    state format:
    {
        "location": "A" or "B",
        "A": "Dirty" or "Clean",
        "B": "Dirty" or "Clean"
    }
    """

    print("Initial State:", state)
    step = 1

    # Run until both rooms are clean
    while state["A"] == "Dirty" or state["B"] == "Dirty":

        print("\nStep", step)
        location = state["location"]

        # Rule 1: If current room is Dirty → Suck
        if state[location] == "Dirty":
            print("Action: Suck")
            state[location] = "Clean"

        # Rule 2: If Clean → Move
        elif location == "A":
            print("Action: Move Right")
            state["location"] = "B"

        elif location == "B":
            print("Action: Move Left")
            state["location"] = "A"

        print("Current State:", state)
        step += 1

    print("\nAll rooms are clean.")
    print("Final State:", state)
