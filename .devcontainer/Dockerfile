FROM mcr.microsoft.com/devcontainers/base:debian-13

# Install gcc, g++, and build utilities
# nodejs and npm are here only to run markdownlint-cli2 below
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    nodejs \
    npm \
    && rm -rf /var/lib/apt/lists/*

# markdownlint-cli2, so that Markdown can be linted from the command line with
# the same rules the VS Code markdownlint extension reads from
# .markdownlint.yml. Usage: markdownlint-cli2 "**/*.md"
RUN npm install -g markdownlint-cli2

# Claude Code:
USER vscode
RUN curl -fsSL https://claude.ai/install.sh | bash

# claudedanger: start Claude Code from the project directory with permission
# checks off. Only reasonable because this container is isolated. The subshell
# keeps the cd from leaking into the calling shell, and running from
# /workspaces/cpp-lab keeps sessions filed under one project so -c and -r find
# them.
RUN echo "alias claudedanger='(cd /workspaces/cpp-lab && claude --dangerously-skip-permissions)'" \
    >> /home/vscode/.bashrc
USER root
