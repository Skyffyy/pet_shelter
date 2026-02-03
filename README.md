# Pet Shelter

This programm simulates pet shelter with different pets workers, each having different own characteristics.

## What is this?

User takes care of animals in a shelter. The animals need food, love and cleaning. You hire workers to help.

## Features

- **Take care of pets**: Each animal has:
  - Happy level
  - Hungry level
  - Clean level

- **Hire workers**: Each worker has:
  - Cleaning skill
  - Selling skill
  - Caring skill
  - Salary

## How to run

Make the program:
```bash
make
```

Run it:
```bash
make run
```

Clean up:
```bash
make clean
```

## Animals

Each animal has:
- **ID** - name tag
- **Name** - what you call it
- **Happy** - starts at 1000
- **Hungry** - how hungry it is
- **Clean** - how nice it looks

## Workers

Each worker has:
- **ID** - name tag
- **Name** - what you call them
- **Skills** - how good they are at things (0-100)
- **Pay** - money each month
- **Hours** - 8 hours to work
