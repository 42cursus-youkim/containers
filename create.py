#!/bin/env python3
"""create boilerplate for your c++ project

Usage:
  ./create.py [-h] [--parent=<parent>] [--namespace=<ns>] <path>
  ./create.py (-h | --help)

Options:
  -n , --namespace <ns>     namespace to use [default: ft]
  -p , --parent <parent>    root of directory path [default: src]

"""

from pathlib import Path
from sys import argv

from docopt import docopt

template = """\
#ifndef {name}{ext}
#define {name}{ext}

{include}

namespace {namespace} {{



}}  // namespace {namespace}

#endif // {name}{ext}
"""


def base_category_name(stem: str) -> str:
    return stem.rsplit("_", maxsplit=1)[0]


def get_include(path: Path) -> str:
    if path.suffix == ".tpp":
        return f'#include "{base_category_name(path.stem)}.hpp"'
    return ""


def main():
    assert __doc__ is not None
    args: dict[str, str] = docopt(__doc__)

    # print(args)
    path = Path(args["<path>"])
    name = f"{path.parent.stem}_{path.stem}"
    ext = path.suffix.replace(".", "_")
    include = get_include(path)

    text = template.format(
        name=name.upper(),
        ext=ext.upper(),
        namespace=args["--namespace"],
        include=include,
    )

    fullpath = Path(__file__).parent / args["--parent"] / args["<path>"]
    fullpath.parent.mkdir(parents=True, exist_ok=True)
    fullpath.write_text(text)


if __name__ == "__main__":
    main()
