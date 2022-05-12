#!/bin/env python3

from pathlib import Path
from sys import argv

template = """\
#ifndef {name}{ext}
#define {name}{ext}

namespace ft {{

}}  // namespace ft

#endif // {name}{ext}
"""


def main():
    if len(argv) != 2:
        print("Usage: create.py <path>")
        return

    raw_path = Path(argv[1])
    name = f"{raw_path.parent.stem}_{raw_path.stem}"
    ext = raw_path.suffix.replace(".", "_")

    path = Path(__file__).parent / "src" / str(raw_path)

    path.parent.mkdir(parents=True, exist_ok=True)
    path.write_text(template.format(name=name.upper(), ext=ext.upper()))


if __name__ == "__main__":
    main()
