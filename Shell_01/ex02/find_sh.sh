find . -type f -name "*.sh" -execdir basename '{}' ';' | cut -f 1 -d '.'
