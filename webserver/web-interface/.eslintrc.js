module.exports = {
  env: {
    browser: true,
    es2021: true,
  },
  extends: [
    'plugin:react/recommended',
    'airbnb',
    'react-app',
    'react-app/jest',
  ],
  parserOptions: {
    ecmaFeatures: {
      jsx: true,
    },
    ecmaVersion: 'latest',
    sourceType: 'module',
  },
  plugins: [
    'react',
  ],
  rules: {
    'max-len': [
      'error',
      {
        code: 120,
        tabWidth: 2,
        comments: 120,
        ignoreComments: true,
        ignoreTrailingComments: true,
        ignoreUrls: true,
        ignoreStrings: true,
        ignoreTemplateLiterals: true,
        ignoreRegExpLiterals: true,
      },
    ],
    'react/jsx-props-no-spreading': 'off',
    'react/self-closing-comp': 'off',
    'react/destructuring-assignment': 'off',
    'react/jsx-no-bind': 'off',
    'react/prop-types': 'off',
    'react/jsx-fragments': 'off',
    'no-plusplus': 'off',
    'import/no-extraneous-dependencies': [
      'error',
      {
        devDependencies: [
          '!./src/setupTests.ts',
        ],
        peerDependencies: true,
      },
    ],
    // allow JSX with any file extension
    'import/extensions': ['.js', '.jsx', '.ts', '.tsx'],
    'react/jsx-filename-extension': [2, { extensions: ['.js', '.jsx', '.ts', '.tsx'] }],
  },
  ignorePatterns: ['build/*.js', 'scripts/*.js', 'config/*.js'],
};
